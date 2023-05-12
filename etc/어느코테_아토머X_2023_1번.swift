// queue 구현은 따로 필요

import Foundation

var dr = [-1, 0, 1, 0]
var dc = [0, -1, 0, 1]

func validateArea(row: Int, column: Int, n: Int) -> Bool {
    return (row >= 0 && row <= n-1 && column >= 0 && column <= n-1)
}

func getGraphAfterExplosion(board: [[Int]], row: Int, column: Int, k: Int) -> [[Int]] {
    var graph = board
    
    for i in 0 ... 3 {
        // 폭발 범위 처리
        for j in 1 ... k {
            let nextRow = row + (dr[i] * j)
            let nextColumn = column + (dc[i] * j)
            
            guard validateArea(row: nextRow, column: nextColumn, n: graph.count)
                    && graph[nextRow][nextColumn] == 0
            else { break }
            
            graph[nextRow][nextColumn] = -1 // 폭발 처리
        }
    }
    
    return graph
}

typealias CostInfo = (row: Int, column: Int, cost: Int)

func bfs(startRow: Int, startColumn: Int, board: [[Int]]) -> [CostInfo] {
    var q = Queue<CostInfo>()
    var costGraph: [[Int]] = Array(repeating: Array(repeating: Int.max, count: board.count), count: board.count)
    
    q.push((row: startRow, column: startColumn, cost: 0))
    
    while(!q.isEmpty) {
        let currentRow = q.front!.row
        let currentColumn = q.front!.column
        let currentCost = q.front!.cost
        
        q.pop()
        
        for i in 0 ... 3 {
            let nextRow = dr[i] + currentRow
            let nextColumn = dc[i] + currentColumn
            let nextCost = currentCost + 1
            
            guard validateArea(row: nextRow, column: nextColumn, n: board.count),
                  (board[nextRow][nextColumn] != 1 && board[nextRow][nextColumn] != 2)
            else { continue }
            
            
            if costGraph[nextRow][nextColumn] > nextCost {
                costGraph[nextRow][nextColumn] = nextCost
                q.push((row: nextRow, column: nextColumn, cost: nextCost))
            }
        }
    }
    
    // 탈출 성공에 소요된 시간 그래프 구하기
    var costInfo = [CostInfo]()
    for row in 0 ..< board.count {
        for column in 0 ..< board.count {
            if board[row][column] == 0 {
                costInfo.append((row: row, column: column, cost: costGraph[row][column]))
            }
        }
    }
    
    return costInfo
}

func solution(_ board:[[Int]], _ k:Int, _ ax:Int, _ ay:Int, _ bx:Int, _ by:Int) -> Int{
    var graph = board

    for row in 0 ..< board.count {
        for column in 0 ..< board.count {
            // 폭발 처리
            if graph[row][column] == 1 {
                graph = getGraphAfterExplosion(board: graph, row: row, column: column, k: k)
            }
        }
    }
    
    // 최소 시간 소요기준으로 오름차순 정렬
    var aCostInfo = bfs(startRow: ax, startColumn: ay, board: graph)
        .sorted { $0.cost < $1.cost }
    
    var bCostInfo = bfs(startRow: bx, startColumn: by, board: graph)
        .sorted { $0.cost < $1.cost }
    
    // 탈출할 수 없으면 -1 반환, 그렇지 않으면 최소 값중 더 큰 값(두개 다 탈출 성공한 경우의 최소 시간) 반환
    return (graph.joined().filter { $0 == 0 }.count != 2)
    ? -1
    : max(aCostInfo.first!.cost, bCostInfo.first!.cost)
}

solution([[1, 2, 0, 0], [1, 0, 2, 0], [1, 0, 0, 0], [1, 0, 0, 1]], 2, 1, 1, 2, 2)
