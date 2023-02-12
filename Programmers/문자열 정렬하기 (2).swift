//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120911
import Foundation

func solution(_ my_string:String) -> String {
    
    return  String(my_string.lowercased().sorted(by: <))
}
