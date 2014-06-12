<?php

/* wdhifSEBundle:Default:result.html.twig */
class __TwigTemplate_1d48ab4091cf3a0f818eb7204168e1a0d3454307cd2aad2627bc383aeb546b7f extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = $this->env->loadTemplate("::base.html.twig");

        $this->blocks = array(
            'title' => array($this, 'block_title'),
            'stylesheets' => array($this, 'block_stylesheets'),
            'body' => array($this, 'block_body'),
            'javascripts' => array($this, 'block_javascripts'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "::base.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $this->parent->display($context, array_merge($this->blocks, $blocks));
    }

    // line 2
    public function block_title($context, array $blocks = array())
    {
        echo "Search Engine";
    }

    // line 3
    public function block_stylesheets($context, array $blocks = array())
    {
        // line 4
        echo "    ";
        $this->displayParentBlock("stylesheets", $context, $blocks);
        echo "
    <link rel=\"stylesheet\" type=\"text/css\" href=\"";
        // line 5
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("css/style.css"), "html", null, true);
        echo "\" xmlns=\"http://www.w3.org/1999/html\">
    <link href=\"";
        // line 6
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("css/bootstrap.min.css"), "html", null, true);
        echo "\" rel=\"stylesheet\" media=\"screen\">
    <link href=\"";
        // line 7
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("css/bootstrap-responsive.css"), "html", null, true);
        echo "\" rel=\"stylesheet\" media=\"screen\">
    <style type=\"text/css\">
        body{
            background-color: #252525;
        }
        .jumbotron{
            text-align: center;
            color: #eeeeee;
            background-color: #252525;
        }
        #scene{
            margin: 0 auto;
            padding: 0;
        }
        .layer:nth-child(1) {
            opacity: 0.15;
        }
        .layer:nth-child(2) {
            opacity: 0.30;
        }
        .layer:nth-child(3) {
            opacity: 0.45;
        }
        .layer:nth-child(4) {
            opacity: 0.60;
        }
        .layer:nth-child(5) {
            opacity: 0.75;
        }
        .layer:nth-child(6) {
            opacity: 0.90;
        }
        .scenediv{
            margin: 0 auto;
            padding: 0;
            max-width: 150px;
        }
        #footer {
            position: absolute;
            bottom: 0;
            width: 100%;
        }
        img {
            display: block;
            width: 100%;
        }
        .result {
            margin-top: -3%;
            background-color: #252525;
        }
        #search {
            padding: 0;
        }
        #inputSearch {
            border-radius: 5px 5px;
            border-color: #5cb85c;
            border-width: 3px;
            height: 34px;
            color: black;
            width: 700px;
        }
        @media screen and (max-width: 850px) {
            .result {
                color: #eeeeee;
                background-color: #252525;
            }
        }
    </style>
    <script type=\"application/javascript\"></script>
";
    }

    // line 77
    public function block_body($context, array $blocks = array())
    {
        // line 78
        echo "    <div class=\"jumbotron\">
        <h1>Intranet Search Engine</h1>
        <p class=\"lead\">The new Search Engine System</p>
        <form id=\"search\">
            <input id=\"inputSearch\" formmethod=\"post\" placeholder=\"Entrez votre recherche...\" type=\"text\" style=\"\">
            <a class=\"btn btn-large btn-success\" href=\"";
        // line 83
        echo $this->env->getExtension('routing')->getPath("result");
        echo "\">Go!</a>
        </form>
    </div>
    <div class=\"container result\">
        <div class=\"panel panel-success\">
            <div class=\"panel-heading\">
                <span class=\"badge\">";
        // line 89
        if (($this->getAttribute((isset($context["pagination"]) ? $context["pagination"] : null), "getTotalItemCount") > 1000)) {
            echo "Environ ";
        }
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["pagination"]) ? $context["pagination"] : null), "getTotalItemCount"), "html", null, true);
        echo " résultat";
        if (($this->getAttribute((isset($context["pagination"]) ? $context["pagination"] : null), "getTotalItemCount") > 1)) {
            echo "s";
        }
        echo "</span>
            </div>
            <div class=\"pages list-group\">
                ";
        // line 92
        $context['_parent'] = (array) $context;
        $context['_seq'] = twig_ensure_traversable((isset($context["pagination"]) ? $context["pagination"] : null));
        foreach ($context['_seq'] as $context["_key"] => $context["page"]) {
            // line 93
            echo "                    <div class=\"list-group-item\">
                        ";
            // line 94
            echo twig_escape_filter($this->env, (isset($context["page"]) ? $context["page"] : null), "html", null, true);
            echo "
                    </div>
                ";
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['_key'], $context['page'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 97
        echo "            </div>
            <div class=\"panel-footer\">
                <div class=\"row\">
                    <div class=\"col-md-8\">
                        <div class=\"navigation\">
                            ";
        // line 102
        echo $this->env->getExtension('knp_pagination')->render((isset($context["pagination"]) ? $context["pagination"] : null));
        echo "
                        </div>
                    </div>
                    <div class=\"col-xs-5 col-md-4 pull-right\">
                        <label for=\"limit\">Number per page</label>
                        <div class=\"input-group\">
                            <input form=\"search-bar\" type=\"text\" id=\"limit\" name=\"limit\" class=\"form-control\" placeholder=\"10\"/>
                                <span class=\"input-group-btn\">
                                    <button class=\"btn btn-default\" type=\"submit\" form=\"search-bar\"><span class=\"glyphicon glyphicon-refresh\"></span></button>
                                </span>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>

";
    }

    // line 120
    public function block_javascripts($context, array $blocks = array())
    {
        // line 121
        echo "    <script src=\"";
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("js/parallax.js"), "html", null, true);
        echo "\"></script>
    <script>
        var scene = document.getElementById('scene');
        var parallax = new Parallax(scene);
    </script>
    ";
        // line 126
        $this->displayParentBlock("javascripts", $context, $blocks);
        echo "
";
    }

    public function getTemplateName()
    {
        return "wdhifSEBundle:Default:result.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  216 => 126,  207 => 121,  204 => 120,  182 => 102,  175 => 97,  166 => 94,  163 => 93,  159 => 92,  146 => 89,  137 => 83,  130 => 78,  127 => 77,  53 => 7,  49 => 6,  45 => 5,  40 => 4,  37 => 3,  31 => 2,);
    }
}
