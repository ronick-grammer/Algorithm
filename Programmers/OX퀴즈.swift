//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120907

import Foundation

func solution(_ quiz:[String]) -> [String] {
    
    var answer = [String]()

    quiz.forEach {
        var splitedString = $0.split(separator: " ")
        
        var first = Int(splitedString[0])!
        var oper = splitedString[1]
        var second = Int(splitedString[2])!
        var result = -1
        
        if oper == "+" {
            result = first + second
        } else {
            result = first - second
        }
        
        answer.append((result == Int(splitedString[4])!) ? "O" : "X")
    }

    return answer
}
