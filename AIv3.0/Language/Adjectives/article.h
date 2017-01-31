#ifndef ARTICLE_H
#define ARTICLE_H

#include <vector>
#include <string>

typedef struct {
	std::string article;

	bool isDefinite; /// the is definite, a is undefinite
} ARTICLE;

class Article {
public:
	Article(void);
	~Article(void);

	void init(void);

	bool isArticle(std::string word);
	bool isArticleInSentence(std::string userSentence);
	bool isArticleInVector(std::vector<std::string> sentenceSplited);

	void addArticle(std::string article);
	void addArticle(std::string article, bool isDefinite);

	std::string getArticle(bool isDefinite);
	std::string getArticle(bool isDefinite, std::string followedBy);


protected:
private:
	std::vector<ARTICLE> _articleList;
};

#endif //ARTICLE_H