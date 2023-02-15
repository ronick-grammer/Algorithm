//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120906
import Foundation

func solution(_ n:Int) -> Int {
    let str = String(n)
    
    var result = 0
    str.forEach { a in
        result += Int(String(a))!
    }
    
    return result
}
