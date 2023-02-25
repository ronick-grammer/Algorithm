import Foundation

public func solution(_ D : inout [Int], _ T : inout [String]) -> Int {
    var p = 0, g = 0, m = 0
    var pDist = 0, gDist = 0, mDist = 0
    
    for (index, value) in T.enumerated() {
        var pCount = 0, gCount = 0, mCount = 0
        
        value.forEach {
            if $0 == "P" {
                pCount += 1
            } else if $0 == "G" {
                gCount += 1
            } else if $0 == "M" {
                mCount += 1
            }
        }
        
        if pCount > 0 {
            p += ((D[index] + pDist) * 2) + pCount
            pDist = 0
        } else {
            pDist += D[index]
        }
        
        if gCount > 0 {
            g += ((D[index] + gDist) * 2) + gCount
            gDist = 0
        } else {
            gDist += D[index]
        }
        
        if mCount > 0 {
            m += ((D[index] + mDist) * 2) + mCount
            mDist = 0
        } else {
            mDist += D[index]
        }
        
        print("p:", p, ", g:", g, ", m:", m)
    }
    
    return max(p, g, m)
}

// 12 반환해야함
//var a = [2, 1, 1, 1, 2]
//var b = ["", "PP", "PP", "GM", ""]

var a = [2, 1, 5, 3, 1, 8]
var b = ["GMG", "PP", "", "GG", "P", ""]

solution(&a, &b)


