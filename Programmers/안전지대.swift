//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120866
import Foundation

// 좌, 아래, 우, 위, 위우대각, 아래좌대각, 아래우대각, 위좌대각
let dr = [-1, 0, 1, 0, 1, -1, 1, -1]
let dc = [0, 1, 0, -1, -1, 1, 1, -1]

func validateArea(row: Int, column: Int, n: Int) -> Bool {
    return (row >= 0 && row <= n-1 && column >= 0 && column <= n-1)
}

func solution(_ board:[[Int]]) -> Int {
    
    var tempBoard = board
    var result = 0
    
    for (row, _) in tempBoard.enumerated() {
        for (column, _) in tempBoard.enumerated() {
            for i in 0 ... 7 {
                if tempBoard[row][column] == 1 {
                    let newDr = row + dr[i]
                    let newDc = column + dc[i]
                    
                    if validateArea(row: newDr, column: newDc, n: tempBoard.count)
                        && tempBoard[newDr][newDc] != 1
                    {
                        tempBoard[newDr][newDc] = -1
                    }
                }
            }
            
        }
    }
    
    return tempBoard.joined().filter { $0 == 0 }.count
}
