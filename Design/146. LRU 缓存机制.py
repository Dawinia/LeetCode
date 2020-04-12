class Node:
    def __init__(self, key=None, data=None):
        self.key = key
        self.data = data
        self.prev = None
        self.next = None


class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.head = Node()
        self.tail = Node()
        self.nodeMap = {}
        self.size = 0
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.nodeMap.keys():
            node = self.nodeMap.get(key)
            self._adjust(node)
            return node.data
        else:
            return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key in self.nodeMap.keys():
            self.nodeMap[key].data = value
            node = self.nodeMap[key]
            self._adjust(node)
            return

        if self.size == self.capacity:
            self.nodeMap.pop(self.head.next.key)
            self.head.next = self.head.next.next
            self.head.next.prev = self.head
            self.size -= 1
        new_node = Node(key, value)
        self.nodeMap[key] = new_node
        new_node.prev = self.tail.prev
        new_node.next = self.tail
        self.tail.prev.next = new_node
        self.tail.prev = new_node
        self.size += 1

    def _adjust(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        node.prev = self.tail.prev
        node.next = self.tail
        self.tail.prev.next = node
        self.tail.prev = node