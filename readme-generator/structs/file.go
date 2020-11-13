package structs

type File struct {
	Filename  string `json:"filename"`
	Additions int    `json:"additions"`
	Deletions int    `json:"deletions"`
	Changes   int    `json:"changes"`
	Status    string `json:"status"`
	RawURL    string `json:"raw_url"`
	BlobURL   string `json:"blob_url"`
	Patch     string `json:"patch"`
}
