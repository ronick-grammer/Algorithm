//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120894?language=swift
import Foundation

let numberString = [
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
]

let numberInt = [
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
]

func solution(_ numbers:String) -> Int64 {
    
    var result = numbers
    
    for (index, value) in numberString.enumerated() {
        result = result.replacingOccurrences(of: value, with: numberInt[index])
    }
    
    return Int64(result)!
}
