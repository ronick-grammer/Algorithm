//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/181921
import Foundation

func solution(_ l:Int, _ r:Int) -> [Int] {
    var result = [Int]()
    
    for i in l ... r {
        let str = String(i)
        
        var isValid = true
        str.forEach {
            if !($0 == "0" || $0 == "5") {
                isValid = false
                return
            }
        }
        
        if isValid {
            result.append(i)
        }
    }
    
    return result.isEmpty ? [-1] : result
}
