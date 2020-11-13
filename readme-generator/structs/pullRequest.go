package structs

import "time"

type PullRequest struct {
	URL                string              `json:"url"`
	ID                 int                 `json:"id"`
	NodeID             string              `json:"node_id"`
	HTMLURL            string              `json:"html_url"`
	DiffURL            string              `json:"diff_url"`
	PatchURL           string              `json:"patch_url"`
	IssueURL           string              `json:"issue_url"`
	CommitsURL         string              `json:"commits_url"`
	ReviewCommentsURL  string              `json:"review_comments_url"`
	ReviewCommentURL   string              `json:"review_comment_url"`
	CommentsURL        string              `json:"comments_url"`
	StatusesURL        string              `json:"statuses_url"`
	Number             int                 `json:"number"`
	State              string              `json:"state"`
	Locked             bool                `json:"locked"`
	Title              string              `json:"title"`
	User               User                `json:"user"`
	Body               string              `json:"body"`
	Labels             []Label             `json:"labels"`
	Milestone          Milestone           `json:"milestone"`
	ActiveLockReason   string              `json:"active_lock_reason"`
	CreatedAt          time.Time           `json:"created_at"`
	UpdatedAt          time.Time           `json:"updated_at"`
	ClosedAt           time.Time           `json:"closed_at"`
	MergedAt           time.Time           `json:"merged_at"`
	MergeCommitSha     string              `json:"merge_commit_sha"`
	Assignee           Assignee            `json:"assignee"`
	Assignees          []Assignee          `json:"assignees"`
	RequestedReviewers []RequestedReviewer `json:"requested_reviewers"`
	RequestedTeams     []RequestedTeam     `json:"requested_teams"`
	Head               Head                `json:"head"`
	Base               Base                `json:"base"`
	Links              Links               `json:"_links"`
	AuthorAssociation  string              `json:"author_association"`
	Draft              bool                `json:"draft"`
}
