//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/134240
import Foundation

func solution(_ food:[Int]) -> String {
    var result = ""
    
    for i in food.indices {
        let foodCount = food[i] / 2
        result += String(repeating: String(i), count: foodCount)
    }
    
    return result + "0" + result.reversed()
}
