# Artificial-Intelligence Semantic-Objects based. Console Application with TTS

This ai is based on the semantic. It extracts the type of words and try to understand a sentence. Words are link between them by concepts. Piano is linked to music for example.
The uml right here: 

https://www.lucidchart.com/documents/view/3432a9e1-b9be-4de6-8057-558353f730cc

Once the sentence is understood, it looks in the memory to answer. 

Objects in the memory are composed of the object_name, the verb associated, the concept(also called object) and the WH words.

Example :
```
Object_name : Myself

verb_associated : Be

concept : Name

List of WH :
What : "Gandalf"
Why : ""
When : ""
Where : ""
Who : ""
How : ""
```

In this case, i'll be able to answer "what is your name ?". It'll answer "I don't know" for the question "why is your name ?" as the string in the WH List is empty.


Another Example :
```
Object_name : Bird

verb_associated : can

concept : Fly

List of WH :
What : ""
Why : "They have wings"
When : ""
Where : ""
Who : ""
How : "They have wings"
```

In this case, i'll be able to answer "Why can birds fly ?" and "How can birds fly ?". In this example, it'll answer the same thing.

To answer questions like "Can bird fly ?", just have to check if the concept and the verb associated exist and are linked in the bird object.


### 28.01.2017 -

Doing Collectioners for language structures and types 

Creating .cpp for pronouns, nouns and verbs to be able to start testing

First test will be to answer the question What is your name ?



## Getting Started

@TODO : Makefile PLEASE :p

### Prerequisites

This project works fine on visual studio community 2015 as I use a TTS (text to speed) library included.

```
Lorem ipsum
```

### Installing

@TODO

```
Lorem ipsum
```


## Running the tests

@TODO

### Break down into end to end tests

@TODO

```
Lorem ipsum
```

### And coding style tests



```
Lorem ipsum
```


## Contributing

@TODO

## Versioning

@TODO

## Authors

@TODO

## License

@TODO

## Acknowledgments

@TODO
