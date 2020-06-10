class Solution(object):
    def backspaceCompare(self, S, T):
        def track(S):
            skip = 0
            for x in reversed(S):
                if x == '#':
                    skip += 1
                elif skip:
                    skip -= 1
                else:
                    yield x

        return all(x == y for x, y in itertools.zip_longest(track(S), track(T)))