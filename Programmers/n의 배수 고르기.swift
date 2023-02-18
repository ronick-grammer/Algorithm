//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120905

import Foundation

func solution(_ n:Int, _ numlist:[Int]) -> [Int] {
    var result = [Int]()
    numlist.forEach {
        if $0 % n == 0 {
            result.append($0)
        }
    }
    return result
}
