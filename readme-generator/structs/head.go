package structs

type Head struct {
	Label string `json:"label"`
	Ref   string `json:"ref"`
	Sha   string `json:"sha"`
	User  User   `json:"user"`
	Repo  Repo   `json:"repo"`
}
