//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120890

import Foundation

func solution(_ array:[Int], _ n:Int) -> Int {

    var array = array
    var comparingNum = Int.max
    var result = 1
    
    // 가장 가까운 수가 우선적으로 고려되어야 하므로 정렬함
    array.sort()
    array.forEach {
        let distance = abs($0.distance(to: n))
        if comparingNum > distance {
            result = $0
            comparingNum = distance
        }
    }
    
    return result
}
