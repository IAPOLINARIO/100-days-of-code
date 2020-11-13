package structs

import "time"

type Milestone struct {
	URL          string    `json:"url"`
	HTMLURL      string    `json:"html_url"`
	LabelsURL    string    `json:"labels_url"`
	ID           int       `json:"id"`
	NodeID       string    `json:"node_id"`
	Number       int       `json:"number"`
	State        string    `json:"state"`
	Title        string    `json:"title"`
	Description  string    `json:"description"`
	Creator      Creator   `json:"creator"`
	OpenIssues   int       `json:"open_issues"`
	ClosedIssues int       `json:"closed_issues"`
	CreatedAt    time.Time `json:"created_at"`
	UpdatedAt    time.Time `json:"updated_at"`
	ClosedAt     time.Time `json:"closed_at"`
	DueOn        time.Time `json:"due_on"`
}
