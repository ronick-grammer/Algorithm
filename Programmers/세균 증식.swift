//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120910
import Foundation

func solution(_ n:Int, _ t:Int) -> Int {
    var result = n
    
    for hour in 1 ... t {
        result = result * 2
    }
    
    return result
}
