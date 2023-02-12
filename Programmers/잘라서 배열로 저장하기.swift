//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120913
import Foundation

func solution(_ my_str:String, _ n:Int) -> [String] {
    
    var resultStr = [String]()
    var offsetIndex = 0
    let quotient = my_str.count / n
    let remainder = my_str.count % n
    
    for _ in 0 ..< quotient {
        let startIndex = my_str.index(my_str.startIndex, offsetBy: offsetIndex)
        let endIndex = my_str.index(my_str.startIndex, offsetBy: offsetIndex + n)
        
        resultStr.append(String(my_str[startIndex ..< endIndex]))
        offsetIndex += n
    }
    
    if remainder != 0 {
        let startIndex = my_str.index(my_str.startIndex, offsetBy: offsetIndex)
        let endIndex = my_str.index(my_str.startIndex, offsetBy: offsetIndex + remainder)
        resultStr.append(String(my_str[startIndex ..< endIndex]))
    }
    
    return resultStr
}
