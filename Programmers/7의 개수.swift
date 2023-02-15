//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120912

import Foundation

func solution(_ array:[Int]) -> Int {
    var result = 0
    
    array.forEach { intNumber in
        let str = String(intNumber)
        
        str.forEach { stringNumber in
            if stringNumber == "7" {
                result += 1
            }
        }
    }
    
    return result
}
