//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120897
import Foundation

func solution(_ n:Int) -> [Int] {
    var result = [Int]()
    
    for num in 1 ... n {
        if n % num == 0 {
            result.append(num)
        }
    }
    
    return result
}
