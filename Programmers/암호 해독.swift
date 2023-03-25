// problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120892

import Foundation

func solution(_ cipher:String, _ code:Int) -> String {
    var currentIndex = code - 1
    var result = ""
    
    while(currentIndex <= cipher.count - 1) {
        let index = cipher.index(cipher.startIndex, offsetBy: currentIndex)
        let char = cipher[index]
        result.append(char)
        
        currentIndex += code
    }
    
    return result
}
