
import themata.fandango

project = 'liblogax'
copyright = '2021, Exotic Libraries - MIT License'
author = 'Adewale Azeez and Other Contributors'

html_theme = 'fandango'
master_doc = 'index'
html_favicon = 'liblogax.png'
main_doc = 'index'
html_static_path = ['_static']

html_css_files = {
    'css/liblogax.css'
}

extensions = ['m2r2', ]
source_suffix = ['.rst', '.md']

html_theme_options = {
    'index_is_single': False,
    'show_navigators_in_index': False,
    #'collapsible_sidebar': False,
    #'collapsible_sidebar_display': 'block',
    'navbar_links': [
        ('Documentation', 'docs/index'),
        ('Reference', 'reference/index'),
        ('Source Code', 'https://github.com/exoticlibraries/liblogax/'),
        ('Exotic Libraries', 'https://exoticlibraries.github.io/')
    ],
    #'has_left_sidebar': True,
    'has_right_sidebar': True,
    'show_navigators': True,
    'syntax_highlighter': 'highlightjs',
    'code_block_editable': False,
    'syntax_highlighter_theme': 'a11y-dark',
    'syntax_highlighter_iframe_embed': False,
    'social_icons': [
        ('fab fa-twitter', 'https://twitter.com/exoticlibs'),
        ('fab fa-github', 'https://github.com/exoticlibraries/liblogax/')
    ],
    'no_sidebar': [
        'index'
    ],
    "source_root": "https://github.com/exoticlibraries/liblogax/edit/main/docs",
    "document_font_size": "17px",
    "metadata": {
        "enable": True,
        "url": "https://exoticlibraries.github.io/liblogax/",
        "type": "website",
        "title": "A robust header only unit testing framework for C programming language.",
        "description": "liblogax is a header only automated testing framework for the C programming language, it requires no dependency and can be downloaded and used in a project immediately.",
        "image": "https://raw.githubusercontent.com/exoticlibraries/liblogax/main/docs/liblogax.png",
        "keywords": "thecarisma, c, cpp, c++, unit testing, framework, exoticlibraries, exotic, libraries, regression, test",
        "author": "Adewale Azeez"
    },
    "twitter_metadata": {
        "enable": True,
        "card": "summary",
        "site": "@exoticlibs",
        "creator": "@iamthecarisma",
        "title": "A robust header only unit testing framework for C programming language.",
        "description": "liblogax is a header only automated testing framework for the C programming language, it requires no dependency and can be downloaded and used in a project immediately.",
        "image": "https://raw.githubusercontent.com/exoticlibraries/liblogax/main/docs/liblogax.png",
    }
}