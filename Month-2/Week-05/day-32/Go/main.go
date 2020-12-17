package main

import "fmt"

func main() {

	boardLeaders := []int{100, 90, 90, 80}
	gamesPlayed := []int{70, 80, 105}

	result := playerRank(boardLeaders, gamesPlayed)

	fmt.Println(result)

}

func playerRank(leaderBoard, gamesPlayed []int) (result []int) {
	n := len(leaderBoard)
	score := make([]int, n)
	uniq := 0

	for i := 0; i < n; i++ {
		sc := leaderBoard[i]
		if uniq > 0 && sc < score[uniq-1] || uniq == 0 {
			uniq++
			score[uniq-1] = sc
		}
	}
	score = score[:uniq]
	curPlace := uniq + 1
	m := len(gamesPlayed)

	for i := 0; i < m; i++ {
		al := gamesPlayed[i]
		for {
			if curPlace == 1 || score[curPlace-2] > al {
				break
			}
			curPlace--
		}
		result = append(result, curPlace)
	}

	return
}
