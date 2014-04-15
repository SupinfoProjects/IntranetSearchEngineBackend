<?php

/* wdhifSEBundle:Default:index.html.twig */
class __TwigTemplate_af96a459d484576e684bf99124eaae7b0a8ffbdb58ab08a742478e763199a626 extends Twig_Template
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

    // line 3
    public function block_title($context, array $blocks = array())
    {
        echo "Search Engine";
    }

    // line 4
    public function block_stylesheets($context, array $blocks = array())
    {
        // line 5
        echo "    ";
        $this->displayParentBlock("stylesheets", $context, $blocks);
        echo "
    <link rel=\"stylesheet\" type=\"text/css\" href=\"";
        // line 6
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("css/style.css"), "html", null, true);
        echo "\">
    <link href=\"";
        // line 7
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("css/bootstrap.css"), "html", null, true);
        echo "\" rel=\"stylesheet\" media=\"screen\">
    <link href=\"";
        // line 8
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("css/bootstrap-responsive.css"), "html", null, true);
        echo "\" rel=\"stylesheet\" media=\"screen\">
    <style type=\"text/css\">
        body{
            background-color: #111;
        }
        .jumbotron{
            text-align: center;
            color: #eeeeee;
            background-color: #111;
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
            max-width: 500px;
        }
        img {
            display: block;
            width: 100%;
        }

    </style>
    <script type=\"application/javascript\"></script>
";
    }

    // line 54
    public function block_body($context, array $blocks = array())
    {
        // line 55
        echo "    <div class=\"jumbotron\">
        <h1>Intranet Search Engine</h1>
        <p class=\"lead\">The new Search Engine System from SoluDev</p>
        <p class=\"lead\">Starting Soon! Stay Tuned &#9786</p>
        <a class=\"btn btn-large btn-success\" href=\"#result\">Read More!</a>
    </div>
    <div class=\"scenediv\">
        <ul id=\"scene\">
            <li class=\"layer\" data-depth=\"0.00\"><img src=\"";
        // line 63
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer1.png"), "html", null, true);
        echo "\"></li>
            <li class=\"layer\" data-depth=\"0.20\"><img src=\"";
        // line 64
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer2.png"), "html", null, true);
        echo "\"></li>
            <li class=\"layer\" data-depth=\"0.40\"><img src=\"";
        // line 65
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer3.png"), "html", null, true);
        echo "\"></li>
            <li class=\"layer\" data-depth=\"0.60\"><img src=\"";
        // line 66
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer4.png"), "html", null, true);
        echo "\"></li>
            <li class=\"layer\" data-depth=\"0.80\"><img src=\"";
        // line 67
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer5.png"), "html", null, true);
        echo "\"></li>
            <li class=\"layer\" data-depth=\"1.00\"><img src=\"";
        // line 68
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("images/layer6.png"), "html", null, true);
        echo "\"></li>
        </ul>
    </div>
";
    }

    // line 73
    public function block_javascripts($context, array $blocks = array())
    {
        // line 74
        echo "    <script src=\"";
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("js/parallax.js"), "html", null, true);
        echo "\"></script>
    <script>

        // Pretty simple huh?
        var scene = document.getElementById('scene');
        var parallax = new Parallax(scene);

    </script>
    ";
        // line 82
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
        return array (  158 => 82,  146 => 74,  143 => 73,  135 => 68,  131 => 67,  127 => 66,  123 => 65,  119 => 64,  115 => 63,  105 => 55,  102 => 54,  53 => 8,  49 => 7,  45 => 6,  40 => 5,  37 => 4,  31 => 3,);
    }
}
