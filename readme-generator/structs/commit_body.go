package structs

type Commit_Body struct {
	URL         string    `json:"url"`
	Sha         string    `json:"sha"`
	NodeID      string    `json:"node_id"`
	HTMLURL     string    `json:"html_url"`
	CommentsURL string    `json:"comments_url"`
	Commit      Commit    `json:"commit"`
	Author      Author    `json:"author"`
	Committer   Committer `json:"committer"`
	Parents     []struct {
		URL string `json:"url"`
		Sha string `json:"sha"`
	} `json:"parents"`
	Stats Stats  `json:"stats"`
	Files []File `json:"files"`
}
