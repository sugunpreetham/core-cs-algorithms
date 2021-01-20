import time
import threading

class TokenBucketLimiter:
    def __init__(self, capacity: int, refill_rate_per_sec: float):
        self.capacity = float(capacity)
        self.refill_rate = refill_rate_per_sec
        self.tokens = self.capacity
        self.last_refill = time.monotonic()
        self.lock = threading.Lock()

    def allow(self, tokens_requested: int = 1) -> bool:
        with self.lock:
            now = time.monotonic()
            elapsed = now - self.last_refill
            self.tokens = min(self.capacity, self.tokens + elapsed * self.refill_rate)
            self.last_refill = now

            if self.tokens >= tokens_requested:
                self.tokens -= tokens_requested
                return True
            return False

if __name__ == "__main__":
    limiter = TokenBucketLimiter(capacity=5, refill_rate_per_sec=2.0)
    for _ in range(5):
        assert limiter.allow() is True
    assert limiter.allow() is False
    print("TokenBucketLimiter verified.")

// Updated: 2021-01-20 - feat(gateway): token-bucket distributed rate limiter in Python
