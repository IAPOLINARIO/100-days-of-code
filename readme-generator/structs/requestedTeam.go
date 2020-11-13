package structs

type RequestedTeam struct {
	ID              int         `json:"id"`
	NodeID          string      `json:"node_id"`
	URL             string      `json:"url"`
	HTMLURL         string      `json:"html_url"`
	Name            string      `json:"name"`
	Slug            string      `json:"slug"`
	Description     string      `json:"description"`
	Privacy         string      `json:"privacy"`
	Permission      string      `json:"permission"`
	MembersURL      string      `json:"members_url"`
	RepositoriesURL string      `json:"repositories_url"`
	Parent          interface{} `json:"parent"`
}
