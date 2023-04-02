//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120886

import Foundation

func solution(_ before:String, _ after:String) -> Int {
    var result = 1
    
    after.forEach { char in
        if before.contains(char) {
            let beforeCount = before.filter { String($0) == String(char) }.count
            let afterCount = after.filter { String($0) == String(char) }.count
            
            if beforeCount != afterCount {
                result = 0
                return
            }
        } else {
            result = 0
            return
        }
    }
    
    return result
}
