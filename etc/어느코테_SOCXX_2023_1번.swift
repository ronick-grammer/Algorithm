func solution(_ height:[Int], _ width:[Int]) -> Int64 {
    var books = [(height:Int, width:Int)]()
    var widthSum = 0
    for (index, value) in height.enumerated() {
        books.append((height: value, width: width[index]))
        widthSum += width[index]
    }

    let sorted = books.sorted {
        if $0.height == $1.height {
            return $0.width > $1.width
        } else {
            return $0.height < $1.height
        }
    }

    var maxValue = Int64.min

    sorted.forEach {
        maxValue = max(Int64(truncating: ($0.height * widthSum) as NSNumber), maxValue)
        widthSum -= $0.width
    }

    return maxValue
}

solution([140,500,21,32], [2,1,3,7])
