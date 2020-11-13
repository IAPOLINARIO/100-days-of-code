package structs

import "time"

type Commit struct {
	URL    string `json:"url"`
	Author struct {
		Name  string    `json:"name"`
		Email string    `json:"email"`
		Date  time.Time `json:"date"`
	} `json:"author"`
	Committer struct {
		Name  string    `json:"name"`
		Email string    `json:"email"`
		Date  time.Time `json:"date"`
	} `json:"committer"`
	Message string `json:"message"`
	Tree    struct {
		URL string `json:"url"`
		Sha string `json:"sha"`
	} `json:"tree"`
	CommentCount int `json:"comment_count"`
	Verification struct {
		Verified  bool        `json:"verified"`
		Reason    string      `json:"reason"`
		Signature interface{} `json:"signature"`
		Payload   interface{} `json:"payload"`
	} `json:"verification"`
}
