//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/132267
import Foundation

func solution(_ a:Int, _ b:Int, _ n:Int) -> Int {
    var restBottle = n
    var result = 0
    
    while(restBottle >= a) {
        let devided = restBottle / a
        let neededBottle = devided * a
        let givenBottle = devided * b
        result += givenBottle
        restBottle = restBottle - neededBottle + givenBottle
    }

    return result
}
