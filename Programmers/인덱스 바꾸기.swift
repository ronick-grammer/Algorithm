//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120895
import Foundation

func solution(_ my_string:String, _ num1:Int, _ num2:Int) -> String {
    var result = my_string
    let firstIndex = my_string.index(my_string.startIndex, offsetBy: num1)
    let secondIndex = my_string.index(my_string.startIndex, offsetBy: num2)
    let firstChar = String(my_string[firstIndex])
    let secondChar = String(my_string[secondIndex])
    
    result.replaceSubrange(firstIndex...firstIndex, with: secondChar)
    result.replaceSubrange(secondIndex...secondIndex, with: firstChar)
    
    return result
}
