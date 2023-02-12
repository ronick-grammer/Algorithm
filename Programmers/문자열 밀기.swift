//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120921
import Foundation

func solution(_ A:String, _ B:String) -> Int {
    var compareToLeft = A
    var resultToLeft = 9999
    
    var count = 0
    count = 0
    A.reversed().forEach {
        
        if compareToLeft == B {
            resultToLeft = count
            return
        }
        
        compareToLeft.removeLast()
        compareToLeft.insert($0, at: compareToLeft.startIndex)
        count += 1
    }
    
    // print(compareToLeft.reversed())
    if compareToLeft.reversed().reversed() == B {
        return resultToLeft
    } else {
        return -1
    }
}
