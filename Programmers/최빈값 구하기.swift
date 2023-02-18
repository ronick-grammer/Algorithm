//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120812

import Foundation

typealias Index = Int
typealias Value = Int

func solution(_ array:[Int]) -> Int {
    var container = [Int].init(repeating: 0, count: 1001)
    
    // 모든 수에 대한 빈도수 측정
    array.forEach {
        container[$0] += 1
    }
    
    var result = [(index: Index, value: Value)]()
    for (index, value) in container.enumerated() {
        result.append((index, value))
    }
    
    // 최대 빈도수를 구하기 위해 정렬
    result.sort { a, b in
        a.value > b.value
    }
    
    // 중복되는 최대 빈도수라면 -1 반환
    if result[0].value == result[1].value {
        return -1
    }
    
    return result.first!.index
}
