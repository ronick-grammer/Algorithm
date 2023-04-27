//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120815
import Foundation

func solution(_ n:Int) -> Int {
    
    var pizzaCount = 1
    
    while((pizzaCount * 6) % n != 0) {
        pizzaCount += 1
    }
    
    return pizzaCount
}
