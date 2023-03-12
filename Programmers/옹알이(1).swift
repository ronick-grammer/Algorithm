//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120956
func solution(_ babbling:[String]) -> Int {
    let possible = ["aya", "ye", "woo", "ma"]
    var result = 0
    
    babbling.forEach { a in
        var substr = a
        possible.forEach {
            // 가능한 옹알이 단어를 " "으로 대체하여 지우고 난 뒤에 단어가 이어지지 않도록 함
            substr = substr.replacingOccurrences(of: $0, with: " ")
        }
        
        // 모든 " "를 없애준다
        substr = substr.replacingOccurrences(of: " ", with: "")
        if substr.isEmpty {
            result += 1
        }
    }
    
    return result
}
