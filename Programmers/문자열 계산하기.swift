//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120902
import Foundation

func calculate(left: Int, right: Int, oper: String) -> Int {
    if oper == "+" {
        return left + right
    } else {
        return left - right
    }
}

func solution(_ my_string:String) -> Int {
    
    let splitedStrs = my_string.split(separator: " ")
    var left = Int(splitedStrs[0])!
    var oper = String(splitedStrs[1])
    
    for index in 2 ..< splitedStrs.count {
        if let right = Int(splitedStrs[index]) {
            left = calculate(left: left, right: right, oper: oper)
        } else {
            oper = String(splitedStrs[index])
        }
    }
    
    return left
}
