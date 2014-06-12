<?php

/* wdhifSEBundle:Default:index.html.twig */
class __TwigTemplate_a9e18b95454aafaa10065c9103caf28ace43a61ddc4c7e87ad2363973e13100b extends Twig_Template
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
        echo "\">
    <link href=\"";
        // line 6
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("css/bootstrap.css"), "html", null, true);
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
            max-width: 300px;
        }
        img {
            display: block;
            width: 100%;
        }
        #search {
            margin-top: 3%;
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
            #inputSearch {
                border-radius: 5px 5px;
                border-color: #5cb85c;
                border-width: 3px;
                height: 34px;
                color: black;
                width: 300px;
            }
        }
    </style>
    <script type=\"application/javascript\"></script>
";
    }

    // line 73
    public function block_body($context, array $blocks = array())
    {
        // line 74
        echo "    <div class=\"jumbotron\">
        <h1>Intranet Search Engine</h1>
        <p class=\"lead\">The new Search Engine System</p>
        <form id=\"search\">
            <input id=\"inputSearch\" formmethod=\"post\" placeholder=\"Entrez votre recherche...\" type=\"text\" style=\"\">
            <a class=\"btn btn-large btn-success\" href=\"";
        // line 79
        echo $this->env->getExtension('routing')->getPath("result");
        echo "\">Go!</a>
        </form>
    </div>
    <div class=\"scenediv\">
        <ul id=\"scene\">
            <li class=\"layer\" data-depth=\"0.00\"><img src=\"";
        // line 84
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer1.png"), "html", null, true);
        echo "\"></li>
            <li class=\"layer\" data-depth=\"0.20\"><img src=\"";
        // line 85
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer2.png"), "html", null, true);
        echo "\"></li>
            <li class=\"layer\" data-depth=\"0.40\"><img src=\"";
        // line 86
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer3.png"), "html", null, true);
        echo "\"></li>
            <li class=\"layer\" data-depth=\"0.60\"><img src=\"";
        // line 87
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer4.png"), "html", null, true);
        echo "\"></li>
            <li class=\"layer\" data-depth=\"0.80\"><img src=\"";
        // line 88
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer5.png"), "html", null, true);
        echo "\"></li>
            <li class=\"layer\" data-depth=\"1.00\"><img src=\"";
        // line 89
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer6.png"), "html", null, true);
        echo "\"></li>
        </ul>
    </div>
";
    }

    // line 93
    public function block_javascripts($context, array $blocks = array())
    {
        // line 94
        echo "    <script src=\"";
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("js/parallax.js"), "html", null, true);
        echo "\"></script>
    <script>
        var scene = document.getElementById('scene');
        var parallax = new Parallax(scene);
    </script>
    ";
        // line 99
        $this->displayParentBlock("javascripts", $context, $blocks);
        echo "
";
    }

    public function getTemplateName()
    {
        return "wdhifSEBundle:Default:index.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  181 => 99,  172 => 94,  169 => 93,  161 => 89,  157 => 88,  153 => 87,  149 => 86,  145 => 85,  141 => 84,  133 => 79,  126 => 74,  123 => 73,  53 => 7,  49 => 6,  45 => 5,  40 => 4,  37 => 3,  31 => 2,);
    }
}
