struct Heap<Element: Comparable> {
    private var elements: [Element] = []
    
    var isEmpty: Bool {
        return elements.isEmpty
    }
    
    var count: Int {
        return elements.count
    }
    
    var top: Element? {
        return elements.first
    }
    
    mutating func insert(_ element: Element) {
        elements.append(element)
        siftUp(elements.count - 1)
    }
    
    mutating func remove() -> Element? {
        guard !isEmpty else {
            return nil
        }
        
        let root = elements[0]
        let last = elements.removeLast()
        
        if !isEmpty {
            elements[0] = last
            siftDown(0)
        }
        
        return root
    }
    
    private mutating func siftUp(_ index: Int) {
        var child = index
        var parent = (child - 1) / 2
        
        while child > 0 && elements[child] > elements[parent] {
            elements.swapAt(child, parent)
            child = parent
            parent = (child - 1) / 2
        }
    }
    
    private mutating func siftDown(_ index: Int) {
        var parent = index
        
        while true {
            var child = parent * 2 + 1
            
            if child >= elements.count {
                break
            }
            
            let rightChild = child + 1
            
            if rightChild < elements.count && elements[rightChild] > elements[child] {
                child = rightChild
            }
            
            if elements[child] <= elements[parent] {
                break
            }
            
            elements.swapAt(child, parent)
            parent = child
        }
    }
}

struct PriorityQueue<Element: Comparable> {
    private var heap = Heap<Element>()
    
    var isEmpty: Bool {
        return heap.isEmpty
    }
    
    var count: Int {
        return heap.count
    }
    
    var top: Element? {
        return heap.top
    }
    
    mutating func push(_ element: Element) {
        heap.insert(element)
    }
    
    mutating func pop() -> Element? {
        return heap.remove()
    }
}
