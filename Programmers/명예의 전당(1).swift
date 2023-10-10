//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/138477
import Foundation

func solution(_ k:Int, _ score:[Int]) -> [Int] {
    var hallOfFame = [Int]()
    var result = [Int]()
    
    var day = 0
    score.forEach {
        hallOfFame.append($0)
        hallOfFame.sort(by: >)
        
        day += 1
        if day > k {
            hallOfFame.removeLast()
        }
        result.append(hallOfFame.last!)
    }
    
    return result
}
