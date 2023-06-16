//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/181855
import Foundation

func solution(_ strArr:[String]) -> Int {
    
    var lengthCount:[Int] = Array(repeating: 0, count: 31)
    
    strArr.forEach {
        lengthCount[$0.count] += 1
    }
    
    return lengthCount.max()!
}
