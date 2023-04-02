//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120887
import Foundation

func solution(_ i:Int, _ j:Int, _ k:Int) -> Int {
    
    var result = 0
    for num in i ... j {
        if String(num).contains(String(k)) {
            result += String(num).filter { String($0) == String(k) }.count
        }
    }
    
    return result
}
