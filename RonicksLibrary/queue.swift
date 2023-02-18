import Foundation

// 출처: https://jeonyeohun.tistory.com/321

class Node<T> {
    let data: T
    var next: Node?
    
    init(data: T, next: Node? = nil) {
        self.data = data
        self.next = next
    }
}

struct TwoPointerLinkedList<T> {
    var head: Node<T>?
    var tail: Node<T>?
    var count: Int = 0
    
    var front: Node<T>? {
        return head
    }
    var back: Node<T>? {
        return tail
    }
    
    mutating func add(node: Node<T>) {
        if self.head == nil {
            self.head = node
            self.tail = node
        } else {
            self.tail?.next = node
            self.tail = node
        }
        self.count += 1
    }
    mutating func removeFirst() -> Node<T>? {
        guard head != nil else {
            self.clear()
            return nil
        }
        let deleted = self.head
        self.head = head?.next
        self.count -= 1
        
        if head == nil {
            self.clear()
        }
        return deleted
    }
    mutating func clear() {
        self.head = nil
        self.tail = nil
        self.count = 0
    }
}

struct Queue<T> {
    var list = TwoPointerLinkedList<T>()
    
    init(_ elements: [T] = []) {
        for element in elements {
            list.add(node: Node(data: element))
        }
    }
    
    var count : Int {
        return list.count
    }
    var isEmpty : Bool {
        return list.head == nil
    }
    var front: T? {
        return list.front?.data
    }
    var back: T? {
        return list.back?.data
    }
    
    mutating func clear () {
        list.clear()
    }
    
    mutating func pop() -> T? {
        return list.removeFirst()?.data
    }
    
    mutating func push(_ element: T) {
        list.add(node: Node(data: element))
    }
}
