//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120896
import Foundation

func solution(_ s:String) -> String {
    let sortedString = String(s.sorted())
    var result = ""
    
    sortedString.forEach {
        if !sortedString.contains(String($0) + String($0)) &&
            !result.contains(String($0)) {
            result.append($0)
        }
    }
    
    return result
}
