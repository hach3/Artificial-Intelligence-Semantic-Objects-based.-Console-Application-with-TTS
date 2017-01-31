#include "article.h"


Article::Article(void)
{
	this->init();
}
Article::~Article(void)
{
	this->_articleList.clear();
}

void Article::init(void)
{
	this->addArticle("A", false);
	this->addArticle("AN", false);
	this->addArticle("THE", true);
}

bool Article::isArticle(std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_articleList.size(); i++)
	{
		if (this->_articleList.at(i).article == word)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Article::isArticleInSentence(std::string userSentence)
{
	bool found = false;
	size_t foundAt;
	for (unsigned int i = 0; i < this->_articleList.size(); i++)
	{
		foundAt = userSentence.find(this->_articleList.at(i).article);
		if (foundAt != std::string::npos)
		{
			found = true;
			break;
		}
	}
	return found;
}
bool Article::isArticleInVector(std::vector<std::string> sentenceSplited)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_articleList.size(); i++)
	{
		for (unsigned int y = 0; y < sentenceSplited.size(); y++)
		{
			if (this->_articleList.at(i).article == sentenceSplited.at(y))
			{
				found = true;
				break;
			}
		}
		if (found)
			break;
	}
	return found;
}

void Article::addArticle(std::string article)
{
	ARTICLE newArticle;
	newArticle.article = article;
	this->_articleList.push_back(newArticle);
}
void Article::addArticle(std::string article, bool isDefinite)
{
	ARTICLE newArticle;
	newArticle.article = article;
	newArticle.isDefinite = isDefinite;
	this->_articleList.push_back(newArticle);
}

std::string Article::getArticle(bool isDefinite)
{
	std::string articleToReturn;
	for (unsigned int i = 0; i < this->_articleList.size(); i++)
	{
		if (this->_articleList.at(i).isDefinite == isDefinite)
		{
			articleToReturn = this->_articleList.at(i).article;
			break;
		}
	}
	return articleToReturn;
}
std::string Article::getArticle(bool isDefinite, std::string followedBy)
{
	std::string articleToReturn;
	for (unsigned int i = 0; i < this->_articleList.size(); i++)
	{
		if (this->_articleList.at(i).isDefinite == isDefinite)
		{
			if (this->_articleList.at(i).article == "A" ||
				this->_articleList.at(i).article == "AN")
			{
				if (followedBy.at(0) == 'A' || followedBy.at(0) == 'E'
					|| followedBy.at(0) == 'I' || followedBy.at(0) == 'O'
					|| followedBy.at(0) == 'U')
				{
					articleToReturn = "AN";
				}
				else {
					articleToReturn = "A";
				}
			}
			else {
				articleToReturn = this->_articleList.at(i).article;
			}
			
			break;
		}
	}
	return articleToReturn;
}