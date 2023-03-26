//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120891
import Foundation

func solution(_ order:Int) -> Int {
    let orderString = String(order)
    var result = 0
    
    orderString.forEach {
        let digit = Int(String($0))!

        if digit != 0 && digit % 3 == 0 {
            result += 1
        }
    }
    
    return result
}
