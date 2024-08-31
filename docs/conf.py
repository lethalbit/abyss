# SPDX-License-Identifier: GPL-2.0-only
import json
import datetime
from subprocess import check_output
from pathlib    import Path
from textwrap   import dedent

ROOT_DIR    = Path(__file__).parent.parent
BUILD_DIR   = (ROOT_DIR / 'build')
DOCS_DIR    = (ROOT_DIR / 'docs')
ABYSS_DIR   = (ROOT_DIR / 'abyss')


def get_proj_version():
	project_info = check_output(['meson', 'introspect', '--projectinfo', BUILD_DIR], cwd = ROOT_DIR).decode('utf8')
	prj_version  = json.loads(project_info).get('version', '0.1.0')
	git_hash     = check_output(['git', 'rev-parse', '--short', 'HEAD'], cwd = ROOT_DIR).decode('utf8').strip()

	if git_hash == '':
		return prj_version

	return f'{prj_version}-{git_hash}'


project   = 'Abyss'
version   = get_proj_version()
release   = version
copyright = f'{datetime.date.today().year}, Aki "lethalbit" Van Ness, et. al.'
language  = 'en'


extensions = [
	'sphinx.ext.githubpages',
	'sphinx.ext.intersphinx',
	'sphinx.ext.todo',
	'sphinx_inline_tabs',
	'sphinxext.opengraph',
	'myst_parser',
]

breathe_projects = {
	'abyss': './_doxygen/xml',
}

primary_domain = 'cpp'
highlight_language = 'cpp'


myst_heading_anchors = 3

html_baseurl     = 'https://lethalbit.github.io/abyss'
html_theme       = 'furo'
html_copy_source = False
html_static_path = [
	'_static'
]

html_theme_options = {
	'top_of_page_buttons': [],
}


autosectionlabel_prefix_document = True
