pipeline {
    agent {
        label 'CPP_DOCKER_AGENT'
    }

    triggers {
        pollSCM 'H/10 * * * *'
    }

    environment {
        APP_NAME = 'MyApplication'
    }

    stages {
        stage('Build') {
            steps {
                echo "Building ${env.APP_NAME}"
                sh 'g++ -std=c++20 -o main main.cpp -luuid'
            }
        }

        stage('Test') {
            steps {
                echo 'Testing the application'
                sh './main'

                stages {
                    stage('test 1') {
                        echo 'Test 1'
                    }

                    stage('test 2') {
                        echo 'Test 2'
                    }

                    stage('test 3') {
                        echo 'Test 3'
                    }
                }

            }
        }

        stage('Deploy') {
            steps {
                echo 'No deployment has been configured yet'
            }
        }
    }

    post {
        success {
            echo 'Build, test, and deployment completed successfully'
            echo "Build number: ${env.BUILD_NUMBER}"
            echo "Build URL: ${env.BUILD_URL}"

            writeFile(
                file: "build-${env.BUILD_NUMBER}.txt",
                text: "SUCCESS: ${env.BUILD_NUMBER} - ${env.BUILD_URL}\n"
            )

            archiveArtifacts(
                artifacts: "build-${env.BUILD_NUMBER}.txt, main",
                fingerprint: true
            )
        }

        failure {
            echo 'One or more stages failed'
        }

        cleanup {
            deleteDir()
        }
    }
}