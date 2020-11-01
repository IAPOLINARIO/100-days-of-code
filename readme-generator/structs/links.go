package structs

type Links struct {
	Self struct {
		Href string `json:"href"`
	} `json:"self"`
	HTML struct {
		Href string `json:"href"`
	} `json:"html"`
	Issue struct {
		Href string `json:"href"`
	} `json:"issue"`
	Comments struct {
		Href string `json:"href"`
	} `json:"comments"`
	ReviewComments struct {
		Href string `json:"href"`
	} `json:"review_comments"`
	ReviewComment struct {
		Href string `json:"href"`
	} `json:"review_comment"`
	Commits struct {
		Href string `json:"href"`
	} `json:"commits"`
	Statuses struct {
		Href string `json:"href"`
	} `json:"statuses"`
}
