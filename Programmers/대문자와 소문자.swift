//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120893
import Foundation

func solution(_ my_string:String) -> String {
    
    var result = ""
    
    my_string.forEach {
        if $0.isLowercase {
            result.append($0.uppercased())
        } else {
            result.append($0.lowercased())
        }
    }
    
    return result
}
