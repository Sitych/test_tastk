# test_tastk

## Тестовое задание для компании "Базовые технологии".

Написан код реализующий следующий функционал:
1. чтение INI файла и заполнение структуры config_t, если значения для поля отсутствует оно должно быть заполнено значением по умолчанию
(значения можно взять произвольные);
2. запись INI файла на основе данных структуры config

## Как скачать?

```
git clone <repository url>
```

## Установка

Скачать репозиторий, затем перейти в папку, куда был скачен проект и запустить команду 

```
make
```

## Как пользоваться?

```
Usage: ./parser (sourcefile.ini|config.ini)
	sourcefile.ini	- файл откуда берутся данные
	config.ini		- файл куда записываются данные (по-другому назвать нельзя)
```

## Что можно улучшить:
1. Добавить обработку названия секции .ini файла
2. Если файл config.ini уже создан, перезаписать его поля
