class Solution:
    def predictPartyVictory(self, senate):
        q1 = collections.deque()
        q2 = collections.deque()

        n = len(senate)

        for i, c in enumerate(senate):
            q1.append(i) if c == "R" else q2.append(i)

        while len(q1) and len(q2):
            ri, di = q1.popleft(), q2.popleft()
            q1.append(ri + n) if ri < di else q2.append(di + n)

        return "Radiant" if len(q1) > len(q2) else "Dire"