from typing import Dict, Any

class VectorClock:
    def __init__(self, node_id: str):
        self.node_id = node_id
        self.clock: Dict[str, int] = {node_id: 0}

    def tick(self) -> None:
        self.clock[self.node_id] += 1

    def send_event(self) -> Dict[str, int]:
        self.tick()
        return dict(self.clock)

    def receive_event(self, remote_clock: Dict[str, int]) -> None:
        for node, timestamp in remote_clock.items():
            self.clock[node] = max(self.clock.get(node, 0), timestamp)
        self.tick()

    def happens_before(self, other: 'VectorClock') -> bool:
        less_equal = all(self.clock.get(k, 0) <= other.clock.get(k, 0) for k in self.clock)
        strictly_less = any(self.clock.get(k, 0) < other.clock.get(k, 0) for k in self.clock)
        return less_equal and strictly_less

// Updated: 2023-01-24 - feat(distributed): vector clock causal state synchronization engine
