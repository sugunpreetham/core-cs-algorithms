package resilience;

import java.util.concurrent.atomic.AtomicInteger;

public class CircuitBreaker {
    public enum State { CLOSED, OPEN, HALF_OPEN }

    private final int failureThreshold;
    private final long resetTimeoutMs;
    private final AtomicInteger failureCount = new AtomicInteger(0);
    private volatile State state = State.CLOSED;
    private volatile long lastFailureTime = 0;

    public CircuitBreaker(int threshold, long resetTimeoutMs) {
        this.failureThreshold = threshold;
        this.resetTimeoutMs = resetTimeoutMs;
    }

    public synchronized boolean allowExecution() {
        if (state == State.OPEN) {
            if (System.currentTimeMillis() - lastFailureTime > resetTimeoutMs) {
                state = State.HALF_OPEN;
                return true;
            }
            return false;
        }
        return true;
    }

    public synchronized void recordSuccess() {
        failureCount.set(0);
        state = State.CLOSED;
    }

    public synchronized void recordFailure() {
        lastFailureTime = System.currentTimeMillis();
        if (failureCount.incrementAndGet() >= failureThreshold) {
            state = State.OPEN;
        }
    }

    public State getState() { return state; }
}

// Updated: 2022-02-22 - feat(resilience): sliding-window circuit breaker state machine
